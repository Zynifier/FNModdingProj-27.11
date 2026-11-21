// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaHUDSituationalFeedback.generated.h"

class UFortDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaHUDSituationalFeedback : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="AthenaHUDFeedbackLine"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_Feedback;

private:
	UPROPERTY(EditAnywhere, Category="AthenaHUDSituationalFeedback")
	bool bPrecreateFeedbackEntries;

};

