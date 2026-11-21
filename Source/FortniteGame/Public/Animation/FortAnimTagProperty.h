// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/MemberReference.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "FortAnimTagProperty.generated.h"

USTRUCT()
struct FAnimTagProperty
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGuid PropertyGuid_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AnimTagProperty")
	FMemberReference PropertyReference;
#endif

	UPROPERTY(EditAnywhere, Category="AnimTagProperty")
	FGameplayTag BackingGameplayTag;

	UPROPERTY(EditAnywhere, Category="AnimTagProperty")
	TFieldPath<FProperty> PropertyToEdit;

	UPROPERTY(VisibleAnywhere, Category="AnimTagProperty")
	FName PropertyName;

	UPROPERTY(EditAnywhere, Category="AnimTagProperty")
	bool bUseExactTag;

};

