// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortBrushSize.h"
#include "FortSquadIcon.generated.h"

class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSquadIcon : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortStat")
	void SetSquad(const FName& InName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStat")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortStat")
	TEnumAsByte<EFortBrushSize::Type> ImageSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortStat", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Icon;

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="FortStat")
	void HandleDifferentSquadSetBP();

};

