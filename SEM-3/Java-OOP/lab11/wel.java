package lab11;
import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.paint.*;
import javafx.scene.control.*;
public class wel extends Application{
  public static void main(String[] args) {
    launch(args);
  }
  public void start(Stage ps){
    ps.setTitle("This is the first JavaFX Application");
    FlowPane fp = new FlowPane(10,10);
    Scene sc = new Scene(fp,500,200);
    Label l = new Label("Welcome to JavaFx programmimg");
    l.setTextFill(Color.MAGENTA);
    ps.setScene(sc);
    ps.show();
  }
}
