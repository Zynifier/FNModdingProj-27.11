// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "McpCommandContexts.h"
#include "McpProfile.h"
#include "FortMcpProfile.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMcpPostProfileUpdate);

USTRUCT(BlueprintType)
struct FMtxBreakdown
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MtxBreakdown")
	int32 AvailableTotalMtx;

	UPROPERTY(BlueprintReadOnly, Category="MtxBreakdown")
	int32 AvailablePremiumMtx;

	UPROPERTY(BlueprintReadOnly, Category="MtxBreakdown")
	int32 UnavailableTotalMtx;

	UPROPERTY(BlueprintReadOnly, Category="MtxBreakdown")
	int32 UnavailablePremiumMtx;

};

UCLASS(MinimalAPI)
class UFortMcpProfile : public UMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(ServiceRequest(MCP))
	void RemoveGiftBox(const TArray<FString>& GiftBoxItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execRemoveGiftBox);

private:
	UFUNCTION(ServiceRequest(MCP))
	void MarkItemSeen(const TArray<FString>& ItemIds, const FClientUrlContext& Context);
	DECLARE_FUNCTION(execMarkItemSeen);

};

