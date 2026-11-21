// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortContextualTutorialController.generated.h"

class AFortPawn;
class AFortPlayerController;
class UFortContextualTutorial;

UCLASS(BlueprintType)
class UFortContextualTutorialController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HideGameModeMessageRequest();

protected:
	UFUNCTION()
	void HandleDamageReceived();

	UFUNCTION()
	void HandleDBNOChanged(AFortPawn* Pawn, bool IsBDNO);

	UFUNCTION()
	void HandleStartSkydivingForActivation();

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortContextualTutorial>> ActiveContextualTutorials;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortContextualTutorial>> PendingContextualTutorials;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortContextualTutorial>> CompletedContextualTutorials;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortContextualTutorial>> PendingCompletedContextualTutorials;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwnerController;

};

