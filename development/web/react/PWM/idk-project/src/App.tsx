import { useState } from "react";
import ExpandableText from "./components/ExpandableText";
import Form from "./components/Form";
import ExpenseList from "./expense-tracker/components/ExpenseList";
import ExpenseFiler from "./expense-tracker/components/ExpenseFiler";
import ExpenseForm from "./expense-tracker/components/ExpenseForm";
import categories from "./expense-tracker/categories";


function App() {
  const [SelectedCategory, setSelectedCategory] = useState("");

  const [expenses, setexpenses] = useState([
    { id: 1, description: "shoping", amount: 100, category: "Personal" },
    { id: 2, description: "fuel", amount: 50, category: "Personal" },
    { id: 3, description: "salary", amount: 5000, category: "Business" },
    { id: 4, description: "software", amount: 200, category: "Business" },
  ]);

  let visibleExpenses = SelectedCategory
    ? expenses.filter((e) => e.category === SelectedCategory)
    : expenses;

  if(SelectedCategory === "ALL Categories") visibleExpenses = expenses;

  return (
    <>
      <div className="mb-5">
        <ExpenseForm onSubmit={ newExpense => setexpenses([{ ...newExpense ,id:expenses.length+1},...expenses ])
         } />
      </div>

      <div className="m-3">
        <ExpenseFiler
          onSelectCategory={(category) => setSelectedCategory(category)}
        />
      </div>
      <ExpenseList
        expenses={visibleExpenses}
        onDelete={(id) => setexpenses(expenses.filter((e) => e.id != id))}
      ></ExpenseList>
    </>
  );
}

export default App;
