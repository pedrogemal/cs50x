//  Created by Pedro Lanzieri on 13/11/20.
//

import UIKit
import MessageUI
import MapKit

class ContactTableViewController : UITableViewController, MFMailComposeViewControllerDelegate, MFMessageComposeViewControllerDelegate {
    
    let options = ["Send email", "Send SMS message", "Send Whatsapp® message", "Call clinic", "Call personal phone", "Get directions"]
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return options.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ContactCell", for: indexPath)
        cell.textLabel?.text = options[indexPath.row]
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {

        switch (indexPath.row) {
                case 0:
                    sendEmail()
                    print("You tapped cell number 0.")
                    break;
                case 1:
                    sendSMSMessage()
                    print("You tapped cell number 1.")
                    break;
                case 2:
                    sendWhatsappMessage()
                    print("You tapped cell number 2.")
                    break;
                case 3:
                    let clinicNumber = "##########"
                    call(number: clinicNumber)
                    print("You tapped cell number 3.")
                    break;
                case 4:
                    let personalNumber = "##########"
                    call(number: personalNumber)
                    print("You tapped cell number 4.")
                    break;
                case 5:
                    getDirections()
                    print("You tapped cell number 5.")
                    break;

                default:
                    print("Out of index")
                    break;
            }
        
    }
    
    func sendEmail() {
        if MFMailComposeViewController.canSendMail() {
            let mail = MFMailComposeViewController()
            mail.mailComposeDelegate = self
            mail.setToRecipients(["myemail@myhost.com"])

            present(mail, animated: true)
        } else {
            print("Could not send email.")
        }
    }

    func mailComposeController(_ controller: MFMailComposeViewController, didFinishWith result: MFMailComposeResult, error: Error?) {
        controller.dismiss(animated: true)
    }
    
    func messageComposeViewController(_ controller: MFMessageComposeViewController, didFinishWith result: MessageComposeResult) {
        }
    
    func sendSMSMessage() {
        let composeVC = MFMessageComposeViewController()
        composeVC.messageComposeDelegate = self
        
        // Configure the fields of the interface.
        composeVC.recipients = ["##########"]
        
        // Present the view controller modally.
        if MFMessageComposeViewController.canSendText() {
            self.present(composeVC, animated: true, completion: nil)
        } else {
            print("Can't send messages.")
        }
    }
    
    func sendWhatsappMessage() {
        
        let urlWhats = "whatsapp://send?text=\("Patient contact")"
        if let urlString = urlWhats.addingPercentEncoding(withAllowedCharacters: NSCharacterSet.urlQueryAllowed) {
              if let whatsappURL = NSURL(string: urlString) {
                    if UIApplication.shared.canOpenURL(whatsappURL as URL) {
                         UIApplication.shared.open(whatsappURL as URL)
                     }
                     else {
                         print("Please install watsapp")
                     }
              }
        }
    }
    
    func call(number: String) {
        
        if let url = URL(string: "tel://\(number)"),
           UIApplication.shared.canOpenURL(url) {
              if #available(iOS 10, *) {
                UIApplication.shared.open(url, options: [:], completionHandler:nil)
               } else {
                   UIApplication.shared.openURL(url)
               }
           } else {
            print("Error making call")
           }
        
    }
    
    func getDirections() {
                
                let latitude = 00.0000
                let longitude = 00.0000

                let appleURL = "http://maps.apple.com/?daddr=\(latitude),\(longitude)"
                let googleURL = "comgooglemaps://?daddr=\(latitude),\(longitude)&directionsmode=driving"
                let wazeURL = "waze://?ll=\(latitude),\(longitude)&navigate=false"

                let googleItem = ("Google Map", URL(string:googleURL)!)
                let wazeItem = ("Waze", URL(string:wazeURL)!)
                var installedNavigationApps = [("Apple Maps", URL(string:appleURL)!)]

                if UIApplication.shared.canOpenURL(googleItem.1) {
                    installedNavigationApps.append(googleItem)
                }

                if UIApplication.shared.canOpenURL(wazeItem.1) {
                    installedNavigationApps.append(wazeItem)
                }

                let alert = UIAlertController(title: "Selection", message: "Select Navigation App", preferredStyle: .actionSheet)
                for app in installedNavigationApps {
                    let button = UIAlertAction(title: app.0, style: .default, handler: { _ in
                        UIApplication.shared.open(app.1, options: [:], completionHandler: nil)
                    })
                    alert.addAction(button)
                }
                let cancel = UIAlertAction(title: "Cancel", style: .cancel, handler: nil)
                alert.addAction(cancel)
                present(alert, animated: true)
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return "Choose contact method"
    }
}
