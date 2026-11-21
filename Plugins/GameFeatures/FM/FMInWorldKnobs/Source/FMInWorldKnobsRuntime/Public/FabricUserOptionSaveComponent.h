// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FabricModulatable.h"
#include "FabricUserOptionSave.h"
#include "LevelSaveSpawnableInterface.h"
#include "FabricUserOptionSaveComponent.generated.h"

class ABuildingActor;
class UFabricUserOptionPresetAsset;
class UFabricUserOptionSaveModulatable;
class UMusicClockComponent;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API UFabricUserOptionSaveComponent : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActiveOverridesChanged);

public:
	UFUNCTION(BlueprintPure)
	FString GetOverrideForParam(const FString& Param) const;

	UFUNCTION(BlueprintPure)
	bool HasOverrideForParam(const FString& Param) const;

	UFUNCTION(BlueprintPure)
	bool IsApplyingOverrides();

	UFUNCTION(BlueprintCallable)
	void SetMusicClock(UMusicClockComponent* MusicClockComponent);

	UFUNCTION(BlueprintCallable)
	void SetPreset(int32 PresetIndex);

	UFUNCTION(BlueprintCallable)
	void SetSaveSlot(int32 SaveSlotIndex);

	UPROPERTY(BlueprintAssignable)
	FOnActiveOverridesChanged OnActiveOverridesChanged;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionSaveComponent")
	TArray<FString> UserOptionsToSave;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricUserOptionSaveComponent")
	int32 MaxSaveSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionSaveComponent")
	FString SaveIndexParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionSaveComponent")
	TArray<TObjectPtr<UFabricUserOptionPresetAsset>> PresetAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionSaveComponent")
	FString PresetIndexParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricUserOptionSaveComponent")
	FString ApplyIndexImmediatelyToggleParam;

	UPROPERTY(Transient)
	TObjectPtr<ABuildingActor> Owner;

	UPROPERTY(Transient)
	TObjectPtr<UFabricUserOptionSaveModulatable> UserOptionSaveModulatable;

	UPROPERTY(Transient)
	TArray<FFabricUserOptionSaveData> Presets;

	UPROPERTY(SaveGame)
	TArray<FFabricUserOptionSaveData> Saves;

	UPROPERTY()
	TSet<FString> FloatUserOptions;

	UPROPERTY(SaveGame)
	int32 ActiveSaveIndex;

	UPROPERTY(SaveGame)
	int32 ActivePresetIndex;

private:
	UFUNCTION()
	void OnAnyOptionUpdated();

};

UCLASS()
class UFabricUserOptionSaveModulatable : public UFabricModulatable
{
	GENERATED_BODY()

};

