// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSettingCollection.h"
#include "FortEnhancedInputSettingCollection.generated.h"

class UInputMappingContext;

UCLASS()
class UFortEnhancedInputSettingCollection : public UFortSettingCollection
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UInputMappingContext>> InputMappingContexts;

};

