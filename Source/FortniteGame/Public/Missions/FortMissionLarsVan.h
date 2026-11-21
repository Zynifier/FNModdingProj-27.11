// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Aircraft/FortAircraft.h"
#include "FortMissionLarsVan.generated.h"

class AFortPlayerController;
class AFortPlayerPawn;
class UArrowComponent;
class UInterpToMovementComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS(BlueprintType)
class AFortMissionLarsVan : public AFortAircraft
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Lars Van")
	void SetPlayerWaitingToJump(AFortPlayerPawn* Waiting);

protected:
	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Van;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> VanApparatus;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> VanBalloon;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> VanFlames;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> Stool;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> Lars;

	UPROPERTY(VisibleAnywhere, Export, Category="Visuals", meta=(EditInline="true"))
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UInterpToMovementComponent> VanMovement;

private:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerController>> WaitingToJump;

};

