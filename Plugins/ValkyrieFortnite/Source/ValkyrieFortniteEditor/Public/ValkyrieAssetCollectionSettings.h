// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ValkyrieAssetCollectionSettings.generated.h"

class UFortCreativeActorCollection;

UENUM()
enum class EValkyrieAssetVisibility : uint8
{
	Hidden = 0,
	Legacy = 1,
	Unreleased = 2,
	Untested = 3,
	Visible = 4,
	Count = 5,
};

UCLASS(Config=Editor, DefaultConfig, meta=(DisplayName="Asset Collection Settings"))
class UValkyrieFortniteAssetCollectionSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeActorCollection> BaseCollection;

	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeActorCollection> UntestedCollection;

	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeActorCollection> UnreleasedCollection;

	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeActorCollection> LegacyCollection;

	UPROPERTY(Config)
	TSoftObjectPtr<UFortCreativeActorCollection> DisallowForImportCollection;

};

