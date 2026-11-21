// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBangWrapperContentInterface.generated.h"

enum class ETutorialType : uint8;

UINTERFACE()
class UFortBangWrapperContentInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortBangWrapperContentInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapperContentButton")
	void OnBangStateChanged(bool bEnabled, int32 Count);

	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapperContentButton")
	void OnStartCallout(FName TutorialObjectiveName, ETutorialType TutorialType);

	UFUNCTION(BlueprintImplementableEvent, Category="BangWrapperContentButton")
	void OnStopCallout();

};

