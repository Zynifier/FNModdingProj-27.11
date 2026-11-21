// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValkyrieValidator.generated.h"

UCLASS(Config=Editor)
class VALKYRIEEDITOR_API UValkyrieValidator : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FString> UnavailableAssetClassesInPlugin;

};

