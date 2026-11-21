// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaPatrolPath.h"
#include "FortCreativePatrolPath.generated.h"

class ABuildingActor;
class AFortCreativeDeviceProp;

UENUM(BlueprintType)
enum class EFortCreativePatrolPathGroup : uint8
{
	Group_None = 0,
	// None value not really used but is to match logic & values in devices BP

	Group_1 = 1,
	Group_2 = 2,
	Group_3 = 3,
	Group_4 = 4,
	Group_5 = 5,
	Group_6 = 6,
	Group_7 = 7,
	Group_8 = 8,
	Group_9 = 9,
	Group_10 = 10,
	Group_11 = 11,
	Group_12 = 12,
	Group_13 = 13,
	Group_14 = 14,
	Group_15 = 15,
	Group_16 = 16,
	Group_17 = 17,
	Group_18 = 18,
	Group_19 = 19,
	Group_20 = 20,
	Group_21 = 21,
	Group_22 = 22,
	Group_23 = 23,
	Group_24 = 24,
	Group_25 = 25,
	Group_26 = 26,
	Group_27 = 27,
	Group_28 = 28,
	Group_29 = 29,
	Group_30 = 30,
	Group_31 = 31,
	Group_32 = 32,
	Group_33 = 33,
	Group_34 = 34,
	Group_35 = 35,
	Group_36 = 36,
	Group_37 = 37,
	Group_38 = 38,
	Group_39 = 39,
	Group_40 = 40,
	Group_41 = 41,
	Group_42 = 42,
	Group_43 = 43,
	Group_44 = 44,
	Group_45 = 45,
	Group_46 = 46,
	Group_47 = 47,
	Group_48 = 48,
	Group_49 = 49,
	Group_50 = 50,
	Group_51 = 51,
	Group_52 = 52,
	Group_53 = 53,
	Group_54 = 54,
	Group_55 = 55,
	Group_56 = 56,
	Group_57 = 57,
	Group_58 = 58,
	Group_59 = 59,
	Group_60 = 60,
	Group_61 = 61,
	Group_62 = 62,
	Group_63 = 63,
	Group_64 = 64,
	Group_65 = 65,
	Group_66 = 66,
	Group_67 = 67,
	Group_68 = 68,
	Group_69 = 69,
	Group_70 = 70,
	Group_71 = 71,
	Group_72 = 72,
	Group_73 = 73,
	Group_74 = 74,
	Group_75 = 75,
	Group_76 = 76,
	Group_77 = 77,
	Group_78 = 78,
	Group_79 = 79,
	Group_80 = 80,
	Group_81 = 81,
	Group_82 = 82,
	Group_83 = 83,
	Group_84 = 84,
	Group_85 = 85,
	Group_86 = 86,
	Group_87 = 87,
	Group_88 = 88,
	Group_89 = 89,
	Group_90 = 90,
	Group_91 = 91,
	Group_92 = 92,
	Group_93 = 93,
	Group_94 = 94,
	Group_95 = 95,
	Group_96 = 96,
	Group_97 = 97,
	Group_98 = 98,
	Group_99 = 99,
	Group_100 = 100,
};

UCLASS(MinimalAPI, BlueprintType)
class AFortCreativePatrolPath : public AFortAthenaPatrolPath
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool HasPatrolValidNavMesh() const;

	UFUNCTION(BlueprintCallable)
	void SetPatrolHasValidNavMesh(const bool bValidNavMesh);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category="PatrolPath")
	TArray<TObjectPtr<AFortCreativeDeviceProp>> CreativePatrolPoints;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FortCreativePatrolPath", meta=(AllowPrivateAccess="true"))
	EFortCreativePatrolPathGroup PatrolPathGroup;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, DuplicateTransient, Category="FortCreativePatrolPath", meta=(AllowPrivateAccess="true"))
	ABuildingActor* CreativePathRenderer;

};

