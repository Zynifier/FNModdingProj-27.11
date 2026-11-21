// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SpecialEventUILibrary.generated.h"

class UObject;

UCLASS()
class USpecialEventUILibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void HideFrontEndStateWidget(const UObject* WorldContextObject, bool bNewlyHidden);

};

