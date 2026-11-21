// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaMapNavigableIconStackOfChallenges.h"
#include "AthenaMapNavigableIconStackOfNoLocationChallenges.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMapNavigableIconStackOfNoLocationChallenges : public UAthenaMapNavigableIconStackOfChallenges
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetChallengesInfo(int32 ChallengesNum, int32 CountOfCompletedChallenges);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_AllChallenges;

};

