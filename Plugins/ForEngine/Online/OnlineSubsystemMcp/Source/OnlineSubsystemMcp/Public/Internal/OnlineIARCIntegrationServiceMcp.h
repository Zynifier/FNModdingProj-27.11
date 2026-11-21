// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineIARCIntegrationServiceMcp.generated.h"

USTRUCT()
struct FOnlineIARCLocaleMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString LanguageId;

	UPROPERTY(Config)
	FString IARCLocaleId;

};

UCLASS(Abstract, Config=Engine)
class ONLINESUBSYSTEMMCP_API UIARCLocaleMappingUtil : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	TArray<FOnlineIARCLocaleMapping> LocaleMappings;

	UPROPERTY(Config)
	FString DefaultLocale;

};

