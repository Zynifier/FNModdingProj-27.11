// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "FortReleaseVersion.h"
#include "FortTandemCharacterData.generated.h"

class UObject;

UCLASS(MinimalAPI, BlueprintType)
class UFortTandemCharacterData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Tags")
	FGameplayTag GameplayTag;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Text")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="Text")
	FText GeneralDescription;

	UPROPERTY(EditAnywhere, Category="Text")
	FText AdditionalDescription;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayAfter="AdditionalEntryDescription"))
	FText BehaviorDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icons", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> ToastIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icons", meta=(AllowedClasses="/Script/Engine.Texture2D,/Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> EntryListIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icons", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> SidePanelIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icons", meta=(AllowedClasses="/Script/Engine.Texture2D, /Script/Engine.MaterialInterface"))
	TSoftObjectPtr<UObject> PunchCardIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Colors")
	FLinearColor SecondaryColor;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

};

