// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortPropertyOverrideData.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortCreativeVolumeLinkComponent.generated.h"

class AFortVolume;
class UObject;
class UPlaylistUserOptions;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLinkedVolumeSet, AFortVolume*, PreviousVolume, AFortVolume*, NewVolume);

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativeVolumeLinkComponent : public UActorComponent, public ILevelSaveSpawnable, public IFortPropertyOverrideDataAccessor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Minigame")
	AFortVolume* GetLinkedVolume();

	UFUNCTION()
	void OnLinkedVolumeSettingsChanged(const FPropertyOverrideData& OverrideData);

	UPROPERTY(BlueprintAssignable)
	FOnLinkedVolumeSet OnLinkedVolumeSet;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCreativeVolumeLinkComponent")
	TObjectPtr<UPlaylistUserOptions> EditorOptionDefinition;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UObject> CachedOptionDefinitionProxy;
#endif

private:
	UFUNCTION()
	void OnRep_LinkedVolume();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LinkedVolume)
	TObjectPtr<AFortVolume> LinkedVolume;

	UPROPERTY(EditAnywhere, Category="FortCreativeVolumeLinkComponent")
	bool bShouldFindVolumeAtStart;

	UPROPERTY(VisibleInstanceOnly, SaveGame, Category="FortCreativeVolumeLinkComponent")
	FPropertyOverrideData LinkedVolumeProperties;

};

