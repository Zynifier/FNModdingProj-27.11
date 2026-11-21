// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FortLevelInstanceSaveContainerInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UFortLevelInstanceSaveContainer : public UInterface
{
	GENERATED_BODY()
};

class IFortLevelInstanceSaveContainer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	FGuid GetLevelInstanceSaveGUID() const;

	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	FString GetLevelInstanceSaveName() const;

};

