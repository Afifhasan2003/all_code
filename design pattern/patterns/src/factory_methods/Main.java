



public class Main {

    interface Notification {
        void send(String recipient, String message);    //by default it is public and abstract
    }

    static class EmailNotification implements Notification {
        @Override
        public void send(String recipient, String message) {
            System.out.println("Email to " + recipient + ": " + message);
        }
    }

    static class SmsNotification implements Notification {
        @Override
        public void send(String recipient, String message) {
            System.out.println("SMS to " + recipient + ": " + message);
        }
    }

    abstract static class NotificationService {     //static because we are inside static main method

        // Factory Method
        public abstract Notification createNotification(String contact);

        public void notifyStudent(String contact, String message) { //it will never know which notification to create
            Notification n = createNotification(contact);
            n.send(contact, message);
        }
    }

    static class EmailService extends NotificationService {
        @Override
        public Notification createNotification(String contact) {
            return new EmailNotification();
        }
    }

    static class SmsService extends NotificationService {
        @Override
        public Notification createNotification(String contact) {
            return new SmsNotification();
        }
    }


    //now if we implement whatsapp
    static class whatsappNotification implements Notification{
        @Override 
        public void send(String recipient, String message){     
            System.out.println("Whatsapp to " + recipient + ": " + message);
        }
    }
    static class whatsappService extends NotificationService{
        @Override
        public Notification createNotification(String contact){
            return new whatsappNotification();
        }
    }



    public static void main(String[] args) {

        NotificationService emailService = new EmailService();
        emailService.notifyStudent("afif@gmail.com", "Exam tomorrow");

        NotificationService smsService = new SmsService();
        smsService.notifyStudent("017XXXXXXXX", "Class cancelled"); 

        NotificationService whatsappService = new whatsappService();
        whatsappService.notifyStudent("afif", "helo");
    }
}