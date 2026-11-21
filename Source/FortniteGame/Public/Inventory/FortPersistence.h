// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPersistence.generated.h"

class UVkPersistence;

UCLASS()
class UFortPersistence : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UVkPersistence> Persistence;

};

