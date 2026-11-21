// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortInteractInterface.h"
#include "FortPlayerPetRepState.generated.h"

class AActor;
class AFortPlayerPawn;
class UAthenaPetItemDefinition;

USTRUCT(BlueprintType)
struct FPetStimuliRepData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PetStimuliRepData")
	FGameplayTag Stimuli;

	UPROPERTY(BlueprintReadOnly, Category="PetStimuliRepData")
	float GameTimeEnd;

};

UCLASS(NotBlueprintable)
class AFortPlayerPetRepState : public AActor, public IFortInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetFortPlayerPawn() const;

protected:
	UFUNCTION()
	void OnRep_LookAtTarget();

	UFUNCTION()
	void OnRep_PetItemDef();

	UFUNCTION()
	void OnRep_StimuliTag();

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_LookAtTarget, Category="FortPlayerPetRepState")
	TObjectPtr<AActor> LookAtTarget;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PetItemDef, Category="FortPlayerPetRepState")
	TObjectPtr<UAthenaPetItemDefinition> PetItemDef;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StimuliTag, Category="FortPlayerPetRepState")
	FPetStimuliRepData StimuliTag;

};

