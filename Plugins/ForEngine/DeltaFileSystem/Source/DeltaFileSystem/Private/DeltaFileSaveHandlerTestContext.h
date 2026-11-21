// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DeltaFileSaveHandlerTestContext.generated.h"

class UDeltaFileSaveHandler;

UCLASS()
class DELTAFILESYSTEM_API UDeltaFileSaveHandlerTestContext : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UDeltaFileSaveHandler> SaveHandler;

};

