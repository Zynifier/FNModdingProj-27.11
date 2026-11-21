// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlayerControllerContext.generated.h"

class AFortPlayerController;

UINTERFACE(MinimalAPI)
class UFortPlayerControllerContext : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortPlayerControllerContext
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Controller")
	AFortPlayerController* GetControllerFromContext() const;

};

