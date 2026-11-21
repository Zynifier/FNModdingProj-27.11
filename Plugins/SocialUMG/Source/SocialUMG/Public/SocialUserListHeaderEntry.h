// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "SocialUserListHeaderEntry.generated.h"

class UTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class SOCIALUMG_API USocialUserListHeaderEntry : public USocialListEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="SocialUserListHeaderEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_ListName;

	UPROPERTY(BlueprintReadWrite, Export, Category="SocialUserListHeaderEntry", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_NumEntries;

};

