// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortLevelDuplicatableInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI, BlueprintType)
class ULevelDuplicatable : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API ILevelDuplicatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void PostFinishDuplication(UObject* SourceObject, bool bReplacesSource);

};

