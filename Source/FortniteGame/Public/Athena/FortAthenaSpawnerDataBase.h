// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortReleaseVersion.h"
#include "FortAthenaSpawnerDataBase.generated.h"

class UFortAthenaSpawnerDataBase;
class UObject;

UCLASS(Abstract, MinimalAPI)
class UFortAthenaSpawnerDataBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Editor Scripting | AI Spawner Data")
	FORTNITEGAME_API FGameplayTagContainer GetDescriptorTag() const;

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	static FORTNITEGAME_API UFortAthenaSpawnerDataBase* GetSpawnerDataDefaultObject(UObject* SourceObject);
#endif

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="Tags")
	FGameplayTagContainer DescriptorTag;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

};

