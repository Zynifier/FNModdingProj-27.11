// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Math/MathFwd.h"
#include "FortBangInterface.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortBangWrapper.generated.h"

UCLASS()
class UFortBangWrapperOld : public UContentWidget, public IFortBangInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="BangWrapper")
	void SetBangVisibility(bool InVisible);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper")
	EFortBangSize Size;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper")
	FVector2D Offset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper")
	EFortBangType BangType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper", meta=(DisplayName="Tutorial Name"))
	FName TutorialNameID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BangWrapper")
	EFortTutorialGlowType TutorialGlowType;

};

