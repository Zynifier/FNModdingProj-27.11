// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VersePersistentVarWeakMapKey.h"
#include "VerseAgent.generated.h"

class AController;

UCLASS(Abstract)
class VERSESIMULATION_API UVerseAgent : public UVersePersistentVarWeakMapKey
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TWeakObjectPtr<AController> Controller;

};

