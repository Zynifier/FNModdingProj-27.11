// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonLegacy.h"
#include "FortAffiliateEntry.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UFortAffiliateEntry : public UCommonButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> OptionDisplayName;

};

