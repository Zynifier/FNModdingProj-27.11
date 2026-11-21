// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieAssetImportDefaults.generated.h"

class UValkyrieAssetImportDefaultsForClass;

UCLASS(BlueprintType, Blueprintable)
class VALKYRIEEDITOR_API UValkyrieAssetImportDefaults : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Import Defaults")
	TArray<TObjectPtr<UValkyrieAssetImportDefaultsForClass>> AssetImportDefaults;

};

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class VALKYRIEEDITOR_API UValkyrieAssetImportDefaultsForClass : public UObject
{
	GENERATED_BODY()

};

