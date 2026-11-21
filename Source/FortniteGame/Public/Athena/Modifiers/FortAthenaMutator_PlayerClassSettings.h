// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_PlayerSettingsBase.h"
#include "FortAthenaMutator_PlayerClassSettings.generated.h"

class AFortMinigame;
class UFortPlayerClassSettingsComponent;
class UObject;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerClassSettings : public AFortAthenaMutator_PlayerSettingsBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ClassSettings")
	bool AddDataSourceForPlayerClass(uint8 ClassSlotIndex, const UObject* DataSource);

	UFUNCTION(BlueprintCallable, Category="ClassSettings")
	bool RemoveDataSource(const UObject* DataSource);

protected:
	UFUNCTION(BlueprintPure, Category="ClassSettings")
	uint8 GetClassContext() const;

	UFUNCTION(BlueprintCallable, Category="ClassSettings")
	void SetClassContext(uint8 ClassSlotIndex);

	UFUNCTION(BlueprintNativeEvent, Category="ClassSettings")
	bool SetupGameRulesForClassContext(AFortMinigame* Minigame);

	UPROPERTY(EditDefaultsOnly, Category="ClassSettings")
	uint8 NumClassSlots;

	UPROPERTY(EditDefaultsOnly, Category="ClassSettings")
	TSubclassOf<UFortPlayerClassSettingsComponent> ClassSettingsClass;

private:
	UPROPERTY(Transient)
	TMap<uint8, FMutatorPlayerSettingsData> ClassSettingsDataMap;

};

UCLASS(BlueprintType, Blueprintable)
class UFortPlayerClassSettingsComponent : public UFortPlayerSettingsComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Transient, Replicated, Category="FortPlayerClassSettingsComponent")
	uint8 ClassSlotIndex;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FText ClassName;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	FText ClassDescription;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Game Rules")
	bool bVisibleInUI;

};

