// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Curie/Elements/Handlers/FortCurieElementDamageSourceInterface.h"
#include "CurieHandlers.h"
#include "FortCurieElementHandlers.generated.h"

USTRUCT()
struct FFortCurieStateSuggestionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieStateSuggestionData", meta=(Categories="CurieState"))
	FGameplayTag StateTag;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieStateSuggestionData", meta=(Categories="CurieState"))
	FGameplayTagQuery AttachedStatesQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieStateSuggestionData")
	bool bIncludeStateParams;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieStateSuggestionData")
	bool bDiscardOnResolve;

};

USTRUCT()
struct FFortCurieInteractStateSuggestionData : public FFortCurieStateSuggestionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieInteractStateSuggestionData")
	bool bAlwaysSuggest;

};

UCLASS(MinimalAPI)
class UFortCurieElementAllocationHandler : public UCurieElementAllocationHandler
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortCurieElementAttachConditionHandler : public UCurieElementAttachConditionHandler
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle ElementMagnitudeToIntensityCurve;

};

UCLASS(MinimalAPI)
class UFortCurieElementAttachHandler : public UCurieElementAttachHandler, public IFortCurieElementDamageSourceInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	TArray<FFortCurieStateSuggestionData> AttachmentSuggestedStates;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	uint8 bActAsDmgSrcDirectly : 1;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(EditCondition="bActAsDmgSrcDirectly"))
	FDataTableRowHandle DamageDataTableRowHandle;

};

UCLASS()
class UFortCurieElementInteractWithContainerHandler : public UCurieElementInteractWithContainerHandler, public IFortCurieElementDamageSourceInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	uint8 bActAsDmgSrcDirectly : 1;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(EditCondition="bActAsDmgSrcDirectly"))
	FDataTableRowHandle DamageDataTableRowHandle;

};

UCLASS(MinimalAPI)
class UFortCurieElementInteractWithElementHandler : public UCurieElementInteractWithElementHandler
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieElementInteractWithElementHandler", meta=(Categories="Curie.Element"))
	FGameplayTag InteractingElementTag;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FScalableFloat InteractMagnitudeThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle ElementMagnitudeToIntensityDecreaseCurve;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FCurveTableRowHandle ElementMagnitudeToIntensityDecayRateCurve;

};

UCLASS()
class UFortCurieElementInteractWithMaterialHandler : public UCurieElementInteractWithMaterialHandler
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Balance")
	FScalableFloat InteractMagnitudeThreshold;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	bool bShouldSuggestElement;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	bool bShouldDisableElementDecay;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	TArray<FFortCurieInteractStateSuggestionData> OnInstantInteractionStateSuggestions;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	TArray<FFortCurieInteractStateSuggestionData> OnBeginInteractionStateSuggestions;

};

UCLASS()
class UFortCurieElementInteractWithSameElementHandler : public UCurieElementInteractWithElementHandler
{
	GENERATED_BODY()

};

