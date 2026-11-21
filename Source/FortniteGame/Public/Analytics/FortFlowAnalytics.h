// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortFlowAnalytics.generated.h"

class AFortPlayerController;
class UWidget;

USTRUCT(BlueprintType)
struct FFlowAnalyticsImpressionSectionContent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FlowAnalyticsImpressionSectionContent")
	FString ContentID;

	UPROPERTY(BlueprintReadWrite, Category="FlowAnalyticsImpressionSectionContent")
	int32 Row;

	UPROPERTY(BlueprintReadWrite, Category="FlowAnalyticsImpressionSectionContent")
	int32 Column;

};

UCLASS()
class UFortFlowAnalytics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Add Impression"))
	static void FireEvent_AddImpression_BP(const FString& SectionID, const TArray<FFlowAnalyticsImpressionSectionContent>& SectionContents);

	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Element Interacted"))
	static void FireEvent_ElementInteracted_BP(const UWidget* Element, const FString& AdditionalDetails);

	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Element Interacted By Name"))
	static void FireEvent_ElementInteractedByName_BP(const AFortPlayerController* FortPC, const FString& ElementName, const FString& AdditionalDetails);

	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Flush Impressions"))
	static void FireEvent_FlushImpressions_BP(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Main View Opened"))
	static void FireEvent_MainViewOpened_BP(const UWidget* View, const TArray<UWidget*>& Elements, const FString& AdditionalDetails);

	UFUNCTION(BlueprintCallable, Category="Flow Analytics", meta=(DisplayName="Fire Event Sub View Opened"))
	static void FireEvent_SubViewOpened_BP(const UWidget* View, const TArray<UWidget*>& Elements, const FString& AdditionalDetails);

};

