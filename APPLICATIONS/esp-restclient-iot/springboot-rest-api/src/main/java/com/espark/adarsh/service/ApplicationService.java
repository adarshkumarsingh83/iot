package com.espark.adarsh.service;

import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Map;


/*
 * @author Adarsh
 * @author $LastChangedBy: adarsh $
 * @version $Revision: 0001 $, $Date:: 15/6/20 10:12 AM#$
 */

@Slf4j
@Service
public class ApplicationService {

    public String getMessage() {
        return "WELCOME TO THE ESPARK " + new SimpleDateFormat("yyyy-MM-dd HH:mm:ssZ").format(new Date());
    }

    public String puttMessage(Map<String, String> data) {
        log.info(data.toString());
        return "DATA POSTED SUCCESSFULLY AT "+ new SimpleDateFormat("yyyy-MM-dd HH:mm:ssZ").format(new Date());
    }
}
