// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavLinkDefinition.h"
#include "AI/FortAITypes.h"
#include "FortNavLinkDefinition.generated.h"

UENUM(meta=(ScriptName="FortNavLinkPatternType"))
namespace EFortNavLinkPattern
{
	enum Type
	{
		Floor = 0,
		Stairs = 1,
		Roof = 2,
		Manual = 3 UMETA(Tooltip="Disable auto detection for this pattern."),
	};
}

UCLASS(MinimalAPI)
class UFortNavLinkDefinition : public UNavLinkDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Pattern")
	FFortNavLinkPattern Pattern;

	UPROPERTY(EditDefaultsOnly, Category="Pattern")
	TArray<FFortNavLinkPattern> AdditionalPatterns;

	UPROPERTY(EditDefaultsOnly, Category="SmashLinks")
	TArray<TEnumAsByte<EBuildingStairsRailing::Type>> StairsRailing;

	UPROPERTY(EditDefaultsOnly, Category="SmashLinks")
	EBuildingFloorRailing FloorRailing;

	UPROPERTY(EditDefaultsOnly, Category="Pattern")
	TEnumAsByte<EFortNavLinkPattern::Type> PatternType;

};

