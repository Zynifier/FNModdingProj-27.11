// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "FortBotStructureBuilder.generated.h"

class AActor;
class ABuildingActor;
class AController;
class UFortBuildingInstructions;
class UPrimitiveComponent;

UCLASS()
class AFortBotStructureBuilder : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Builder")
	void BuildAll();

	UFUNCTION(BlueprintCallable, Category="Builder")
	void RunDeconstructor();

protected:
	UFUNCTION()
	void OnBuildingDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UPROPERTY(VisibleAnywhere, Transient, Category="Builder")
	TObjectPtr<UFortBuildingInstructions> BuildingInstructions;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingActor>> BuiltActors;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CachedGoal;

};

