// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VerseAsset.generated.h"

class UObject;

UCLASS(Abstract)
class VERSENATIVE_API UVerseAsset : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TSubclassOf<UObject> AssetClass;

};

