// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortSanitizationServiceTypes.h"
#include "FortSanitizationService.generated.h"

UCLASS()
class UFortSanitizationService : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TMap<uint32, FSanitizationData> PendingRequests;

};

