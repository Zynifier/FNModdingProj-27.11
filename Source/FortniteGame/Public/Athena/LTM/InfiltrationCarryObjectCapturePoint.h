// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "InfiltrationCarryObjectCapturePoint.generated.h"

class AFortPlayerPawn;

UCLASS()
class AInfiltrationCarryObjectCapturePoint : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(NetMulticast, Reliable)
	void MulticastIntelCaptured();

protected:
	UFUNCTION()
	virtual void IntelTagCallback(const FGameplayTag Tag, int32 NewCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewUIDetailState(bool bDetailed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewUIVisibilityState(bool bVisible);

	UFUNCTION(BlueprintCallable)
	void OnPawnBeginOverlap(AFortPlayerPawn* TouchingPawn);

	UFUNCTION(BlueprintCallable)
	void OnPawnEndOverlap(AFortPlayerPawn* TouchingPawn);

	UFUNCTION()
	void OnRep_bCapturePointEnabled();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOnIntelCapturedFX();

	UFUNCTION(BlueprintCallable)
	void StartUpdatingUIVisibility();

	UFUNCTION(BlueprintCallable)
	void StopUpdatingUIVisibility();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay Tags")
	FGameplayTagContainer GameplayTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	float UIShowDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UI")
	float UIDetailDistance;

	UPROPERTY(ReplicatedUsing=OnRep_bCapturePointEnabled)
	bool bCapturePointEnabled;

};

