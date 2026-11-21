// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Entity.generated.h"

class ULevel;

UCLASS()
class ENTITYCORE_API UEntity : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<ULevel> Level;

};

