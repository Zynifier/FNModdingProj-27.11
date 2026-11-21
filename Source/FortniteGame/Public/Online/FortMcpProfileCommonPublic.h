// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.h"
#include "Online/FortMcpProfile.h"
#include "FortMcpProfileCommonPublic.generated.h"

USTRUCT(BlueprintType)
struct FFortCommonPublicPersona
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCommonPublicPersona")
	FString BannerIconId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCommonPublicPersona")
	FString BannerColorId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCommonPublicPersona")
	FString HomebaseName;

};

UCLASS(MinimalAPI)
class UFortMcpProfileCommonPublic : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void SetHomebaseBanner(const FString& HomebaseBannerIconId, const FString& HomebaseBannerColorId, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetHomebaseBanner);

	UFUNCTION(ServiceRequest(MCP))
	void SetHomebaseName(const FString& HomebaseName, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execSetHomebaseName);

};

