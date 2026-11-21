// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CatalogTypes.h"
#include "McpVerifierModeSelector.generated.h"

UCLASS(Config=Game)
class GAMESUBCATALOG_API UMcpVerifierModeSelector : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	uint32 RangeStart;

	UPROPERTY(Config)
	uint32 RangeEnd;

	UPROPERTY(Config)
	FString Salt;

	UPROPERTY(Config)
	EVerifierModeOverride VerifierModeOverride;

	UPROPERTY(Config)
	int32 ReceiptRefactorVersionOverride;

};

