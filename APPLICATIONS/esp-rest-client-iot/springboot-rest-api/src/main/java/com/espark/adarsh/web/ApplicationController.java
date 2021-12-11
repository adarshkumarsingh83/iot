package com.espark.adarsh.web;

import com.espark.adarsh.service.ApplicationService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

/*
 * @author Adarsh
 * @author $LastChangedBy: adarsh $
 * @version $Revision: 0001 $, $Date:: 15/6/20 10:12 AM#$
 */

@Slf4j
@RestController
public class ApplicationController {

    @Autowired
    ApplicationService applicationService;

    @GetMapping("/api/espark")
    public String getWish() throws Exception {
        return this.applicationService.getMessage();
    }

    @PostMapping("/api/espark")
    public String postWish(@RequestBody Map<String, String> data) {
        return this.applicationService.puttMessage(data);
    }
}
