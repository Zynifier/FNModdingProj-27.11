// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListViewBase.h"
#include "Types/SlateEnums.h"
#include "AthenaMapChallengeListView.generated.h"

UCLASS(meta=(DisableNativeTick, EntryClass="AthenaMapChallengeListEntry"))
class UAthenaMapChallengeListView : public UListViewBase
{
	GENERATED_BODY()

public:
	UAthenaMapChallengeListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(EditAnywhere, Category="AthenaMapChallengeListView")
	TEnumAsByte<EOrientation> Orientation;

};

