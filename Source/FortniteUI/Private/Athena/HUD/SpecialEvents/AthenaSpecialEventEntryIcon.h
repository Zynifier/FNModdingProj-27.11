// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortUrgentQuestData.h"
#include "AthenaSpecialEventEntryIcon.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpecialEventEntryIcon : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaSpecialEventEntryIcon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintCallable)
	bool LoadAndSetIcon(const FUrgentQuestData& UrgentQuestData);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpecialEventEntryIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_UrgentIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpecialEventEntryIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_UrgentIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpecialEventEntryIcon", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_AlertBackground;

};

