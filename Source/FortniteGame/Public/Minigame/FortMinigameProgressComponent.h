// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Minigame/FortMinigameLogicComponent.h"
#include "FortMinigameProgressComponent.generated.h"

class APlayerState;
class UFortMinigameProgressComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerProgressDelegate, APlayerState*, PlayerState, UFortMinigameProgressComponent*, Progress);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameProgressComponent : public UFortMinigameLogicComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Minigame")
	void AbortProgress(APlayerState* PlayerState);

	UFUNCTION(BlueprintPure, Category="Minigame")
	bool HasActivationTime() const;

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void RevertProgress(APlayerState* PlayerState);

	UFUNCTION(BlueprintCallable, Category="Minigame")
	void StartProgress(APlayerState* PlayerState);

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FPlayerProgressDelegate ProgressStartedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FPlayerProgressDelegate ProgressFinishedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FPlayerProgressDelegate ProgressAbortedDelegate;

	UPROPERTY(BlueprintAssignable, Category="Minigame")
	FPlayerProgressDelegate ProgressRevertedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Minigame")
	float ActivationTime;

protected:
	UFUNCTION()
	void FinishProgress(APlayerState* PlayerState);

};

