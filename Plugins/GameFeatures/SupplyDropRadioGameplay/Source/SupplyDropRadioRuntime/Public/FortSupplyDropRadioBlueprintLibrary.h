// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortSupplyDropRadioBlueprintLibrary.generated.h"

class AFortPlayerControllerGameplay;

UCLASS(meta=(ScriptName="FortSupplyDropRadioLibrary"))
class UFortSupplyDropRadioBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Conversation")
	static void SetMoveShouldAbortConversation(AFortPlayerControllerGameplay* PlayerController, const bool bNewMoveAbortConversation);

	UFUNCTION(BlueprintCallable, Category="Conversation")
	static void StopCurrentConversation(AFortPlayerControllerGameplay* PlayerController);

};

