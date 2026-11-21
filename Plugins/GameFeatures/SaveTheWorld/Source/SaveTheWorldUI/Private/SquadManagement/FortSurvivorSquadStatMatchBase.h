// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "FortMultiSize.h"
#include "FortUITypes.h"
#include "FortSurvivorSquadStatMatchBase.generated.h"

UENUM(BlueprintType)
enum class EFortUISurvivorSquadMatchType : uint8
{
	Multi = 0,
	Single = 1,
	Summary = 2,
	Max_None = 3 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FFortUISurvivorSquadStatMatch
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	FFortMultiSizeBrush Icons;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	FText MagnitudeText;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	FText AttributeDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	int32 NumMembersMeetingCriteria;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	int32 NumMembersRequired;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	EFortUISurvivorSquadMatchType MatchType;

	UPROPERTY(BlueprintReadOnly, Category="Set Bonus")
	EFortBuffState PreviewEffect;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSurvivorSquadStatMatchBase : public UCommonUserWidget, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Survivor Squad Stat Match")
	void OnStatMatchUpdated(FFortUISurvivorSquadStatMatch UpdatedMatch);

	UPROPERTY(BlueprintReadOnly, Category="Survivor Squad Stat Match")
	FFortUISurvivorSquadStatMatch StatMatch;

};

