// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortActivityListItemWrapper.generated.h"

class UFortGameActivity;

UCLASS()
class UFortActivityListItemWrapper : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> GameActivity;

};

