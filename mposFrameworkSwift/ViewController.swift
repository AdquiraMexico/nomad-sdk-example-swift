//
//  ViewController.swift
//  mposFrameworkSwift
//
//  Created by Ricardo Zertuche on 11/13/17.
//  Copyright © 2017 Ricardo Zertuche. All rights reserved.
//

import UIKit

class ViewController: UIViewController, BBVADelegate {
    
    @IBOutlet var scan: UIButton?
     let bbvaNomad = BBVANomad();

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        //self.bbvaAPI.delegate = self;
      
        bbvaNomad.delegate = self
        bbvaNomad.login(withUsername: "v1", andPassword: "v1", andEnv: "D")
        
        scan!.addTarget(self, action: #selector(scanStuff), for: .touchDown)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @objc private func scanStuff(){
        print("escanea")
       // bbvaNomad.initBBVANomad()
        
        bbvaNomad.scanNomad()
        //connectionResult(withSuccess:true)
//bbvaNomad.connect(toNomad:"E405091A-5B26-4FA9-B1BE-EA3DEE58349F")
    }
    
    func loginSucceded(_ success: Bool, andToken token: String!, andDictionary info: [AnyHashable : Any]!) {
        print("sirvo")
        print(info);

    }
    
    func connectionResult(withSuccess success: Bool, andResult result: [Any]!) {
        print("holi")
        print(result)
        bbvaNomad.connect(toNomad: IndexPath(row: 0, section: 0))
    }
    
    func didFinishPaymentCorrectly(_ success: Bool, withTransactin transaction: String!) {
        print(transaction)
    }


    func scanBluetooth() {
        
      //  bbvaNomad.scanNomad()
        //createPopUpLoader(withMessage: "Buscando dispositivos")
    }

}

