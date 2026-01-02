import { z } from "zod";
import { useForm } from "react-hook-form";
import { zodResolver } from "@hookform/resolvers/zod";
import categories from "../categories";

const schema = z.object({
  description: z.string().min(3).max(50),
  amount: z.number().min(0.001).max(100_000),
  category: z.enum(categories), //enum accepts only true consts
});

type ExpenseFormData = z.infer<typeof schema>; //ExpenseFormData is like a interface

interface Props {
  onSubmit: (data: ExpenseFormData) => void;
}

const ExpenseForm = ({ onSubmit }: Props) => {
  const {
    register,
    handleSubmit,
    formState: { errors },
    reset
  } = useForm<ExpenseFormData>({ resolver: zodResolver(schema) });

  return (
    <form
      onSubmit={handleSubmit(data => {
        onSubmit(data);
        reset();
      })}
    >
      <div className="mb-3">
        <label htmlFor="Description" className="form-label">
          Description
        </label>
        <input
          {...register("description")}
          id="Description"
          type="text"
          className="form-control"
        />
        {errors.description && (
          <p className="text-danger"> {errors.description.message} </p>
        )}
      </div>
      <div className="mb-3">
        <label htmlFor="Amount" className="form-label">
          Amount
        </label>
        <input
          {...register("amount", { valueAsNumber: true })}
          id="Amount"
          type="number"
          className="form-control"
        />
        {errors.amount && (
          <p className="text-danger"> {errors.amount.message} </p>
        )}
      </div>
      <div className="mb-3">
        <label htmlFor="Category" className="form-label">
          {" "}
          Category{" "}
        </label>

        <select {...register("category")} className="form-select" id="Category">
          <option value=""></option>
          {categories.map((cat) => (
            <option key={cat} value={cat}>
              {cat}
            </option>
          ))}
        </select>
        {errors.category && (
          <p className="text-danger"> {errors.category.message} </p>
        )}
      </div>
      <button className="btn btn-primary">Add</button>
    </form>
  );
};

export default ExpenseForm;
