// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_SetMarker.generated.h"

UENUM(BlueprintType)
enum class EFortMarkerIncrementType : uint8
{
	//Increments by 1

	Single = 0,
	//Increments by distance between the Author and the marked target in meters

	Distance = 1,
	//Increments by the stack size of the marked items

	StackSize = 2,
};

USTRUCT(meta=(DisplayName="Set Marker"))
struct FFortObjectiveFilter_SetMarker : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker")
	FObjectiveSubjectTags_Progressible MarkedTarget;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker")
	FObjectiveSubjectTags MarkerTags;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker")
	TArray<EFortWorldMarkerType> RequiredMarkerTypes;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker")
	TArray<EFortWorldMarkerType> ProhibitedMarkerTypes;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker", meta=(EditCondition="bUseDistance", ForceUnits="Meters", UIMin="0"))
	FDoubleRange RequiredDistance;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker", meta=(EditCondition="bUseStackSize", UIMin="0"))
	FInt32Range RequiredStackSize;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker", meta=(DisplayPriority="-1"))
	EFortMarkerIncrementType IncrementBy;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker", meta=(InlineEditConditionToggle))
	uint8 bUseStackSize : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_SetMarker", meta=(InlineEditConditionToggle))
	uint8 bUseDistance : 1;

};

UCLASS()
class UFortObjectiveProcessor_SetMarker : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

