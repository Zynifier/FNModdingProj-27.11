// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelInstance/LevelInstanceInterface.h"
#include "Misc/Guid.h"
#include "Creative/FortCreativeDeviceProp.h"
#include "FortLevelInstanceDeviceBase.generated.h"

class AGameplayVolume;
class UFortLevelStreamComponent;
class ULevelInstanceComponent;
class UWorld;

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortLevelInstanceDeviceBase : public AFortCreativeDeviceProp, public ILevelInstanceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AGameplayVolume* GetGameplayVolume() const;

	UFUNCTION()
	void OnRep_LevelInstanceSpawnGuid();

	UFUNCTION(BlueprintCallable)
	void SetLastUsedLevelName(const FString& InLevelName);

	virtual const FLevelInstanceID& GetLevelInstanceID() const override;

	virtual bool HasValidLevelInstanceID() const override;

	virtual const FGuid& GetLevelInstanceGuid() const override;

	virtual const TSoftObjectPtr<UWorld>& GetWorldAsset() const override;

	virtual bool IsLoadingEnabled() const override;

#if WITH_EDITOR
	virtual ULevelInstanceComponent* GetLevelInstanceComponent() const override;

	virtual ELevelInstanceRuntimeBehavior GetDesiredRuntimeBehavior() const override;

	virtual ELevelInstanceRuntimeBehavior GetDefaultRuntimeBehavior() const override;
#endif

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ApplyLastUsedSettings(FGuid LevelGuid, const FString& LevelName, int32 SizeX, int32 SizeY, int32 Height);

	UFUNCTION(BlueprintCallable)
	void AttemptToLoadLastUsedSettings();

	UFUNCTION(BlueprintCallable)
	void StreamLevelsByWorldAsset(UPARAM(ref) TSoftObjectPtr<UWorld>& StreamLevelWorldAsset);

	UFUNCTION(BlueprintCallable)
	void UnloadAllStreamedLevels();

	UPROPERTY(BlueprintReadWrite, Replicated, Category="FortLevelInstanceDeviceBase")
	TObjectPtr<AGameplayVolume> GameplayVolume;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LevelInstanceSpawnGuid)
	FGuid LevelInstanceSpawnGuid;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<ULevelInstanceComponent> LevelInstanceComponent;
#endif

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelStreamComponent> FortLevelStreamComponent;

	UPROPERTY(EditAnywhere, Category="Level", meta=(DisplayName="Level", NoCreate))
	TSoftObjectPtr<UWorld> WorldAsset;

};

