// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.generated.h"

USTRUCT(BlueprintType)
struct FBaseUrlContext
{
	GENERATED_BODY()

};

USTRUCT()
struct MCPPROFILESYS_API FClientUrlContext : public FBaseUrlContext
{
	GENERATED_BODY()

};

USTRUCT()
struct MCPPROFILESYS_API FDedicatedServerUrlContext : public FBaseUrlContext
{
	GENERATED_BODY()

};

USTRUCT()
struct MCPPROFILESYS_API FPublicUrlContext : public FBaseUrlContext
{
	GENERATED_BODY()

};

