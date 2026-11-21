// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortPlayerCustomizableInterface.h"
#include "FortAthenaMutator_WeaponSettings.generated.h"

class UFortItemDefinition;
class UFortWeaponSettingsComponent;
class UObject;

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_WeaponSettings : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddDataSourceForClassSlot(UFortItemDefinition* ItemDefinition, const uint8 ClassSlot, UObject* DataSource);

	UFUNCTION(BlueprintCallable)
	void AddDataSourceForTeam(UFortItemDefinition* ItemDefinition, const uint8 TeamIndex, UObject* DataSource);

	UFUNCTION(BlueprintCallable)
	void RemoveDataSource(UObject* DataSource);

protected:
	UPROPERTY(Transient, Replicated, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortWeaponSettingsComponent>> WeaponSettings;

	UPROPERTY(Transient)
	bool Enabled;

	UPROPERTY(Transient)
	bool bEnabledInPreGame;

	UPROPERTY(Transient)
	float RangeMultiplier;

};

UCLASS()
class UFortWeaponSettingsComponent : public UActorComponent, public IFortPlayerCustomizable
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	bool bPickAxe;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(Transient, Replicated)
	uint8 TeamIndex;

	UPROPERTY(Transient, Replicated)
	uint8 ClassSlot;

	UPROPERTY(Transient, Replicated)
	float RangeMultiplier;

	UPROPERTY(Transient, Replicated)
	float ConeAngleMultiplier;

	UPROPERTY(Transient, Replicated)
	bool Enabled;

	UPROPERTY(Transient)
	bool bEnabledInPreGame;

	UPROPERTY(Transient)
	TObjectPtr<UObject> DataSource;

	UPROPERTY(Transient, Replicated)
	TArray<FName> OverriddenPropertyNames;

};

